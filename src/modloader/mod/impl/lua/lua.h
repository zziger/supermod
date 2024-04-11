#pragma once

#include <filesystem>


#define SOL_LUAJIT 0
#define SOL_ALL_SAFETIES_ON 1
#define SOL_EXCEPTIONS_ALWAYS_UNSAFE 1

#include <sol/sol.hpp>
#include <spdlog/spdlog.h>

namespace sol
{
    template <>
    struct is_automagical<std::filesystem::path> : std::false_type {};

    template <>
    struct is_container<std::filesystem::path> : std::false_type {};


    template <typename T>
    inline bool is_usertype_registered(lua_State* L)
    {
        using u_traits = usertype_traits<T>;

        const char* gcmetakey = &u_traits::gc_table()[0];
        stack::get_field<true>(L, gcmetakey);
        auto res = stack::check<user<u_detail::usertype_storage<T>>>(L);
        lua_pop(L, 1);
        return res;
    }

    template <typename TLua, typename TReal, typename TClass>
        requires requires { static_cast<TLua>(std::declval<TReal>()); static_cast<TReal>(std::declval<TLua>()); }
    inline decltype(auto) property_static_cast(TReal TClass::* property)
    {
        return sol::property(
            [property](const TClass& obj) { return static_cast<TLua>(obj.*property); },
            [property](TClass& obj, TLua val) { return obj.*property = static_cast<TReal>(val); }
        );
    }

    template <typename TLua, typename TReal, typename TClass>
        requires requires { static_cast<TLua>(std::declval<TReal>()); static_cast<TReal>(std::declval<TLua>()); }
    inline decltype(auto) readonly_static_cast(TReal TClass::* property)
    {
        return sol::property(
            [property](const TClass& obj) { return static_cast<TLua>(obj.*property); }
        );
    }

    template <typename TLua, typename TReal, typename TClass>
        requires requires { reinterpret_cast<TLua>(std::declval<TReal>()); reinterpret_cast<TReal>(std::declval<TLua>()); }
    inline decltype(auto) property_reinterpret_cast(TReal TClass::* property)
    {
        return sol::property(
            [property](const TClass& obj) { return reinterpret_cast<TLua>(obj.*property); },
            [property](TClass& obj, TLua val) { return obj.*property = reinterpret_cast<TReal>(val); }
        );
    }

    template <typename TLua, typename TReal, typename TClass>
        requires requires { reinterpret_cast<TLua>(std::declval<TReal>()); reinterpret_cast<TReal>(std::declval<TLua>()); }
    inline decltype(auto) readonly_reinterpret_cast(TReal TClass::* property)
    {
        return sol::property(
            [property](const TClass& obj) { return reinterpret_cast<TLua>(obj.*property); }
        );
    }

    template <typename T>
    struct function_wrapper;

    template <typename Result, typename... Args>
    struct function_wrapper<Result(Args...)>
    {
        template <typename Fn>
        static auto convert(Fn fn) -> std::function<Result(Args...)>
        {
            return [fn](Args&&... args) { return fn(std::forward<Args>(args)...); };
        }
    };

    template <typename Fnt, typename Fn>
    decltype(auto) resolve_conv(Fn fn) {
        return function_wrapper<Fnt>::convert(fn);
    }

    template <typename... Args, typename Fn>
    decltype(auto) overload_conv(Fn fn) {
        return sol::overload_set<std::function<Args>...>(function_wrapper<Args>::convert(fn)...);
    }

    template <typename R, typename C, typename... Args>
    auto bind_instance(R (C::* fn)(Args...), C* inst) {
        return sol::as_function([inst, fn](Args&&... args) { return (inst->*fn)(std::forward<Args>(args)...); });
    }
    template <typename R, typename C, typename... Args>
    auto bind_instance(R (C::* fn)(Args...) const, C* inst) {
        return sol::as_function([inst, fn](Args&&... args) { return (inst->*fn)(std::forward<Args>(args)...); });
    }
    template <typename R, typename C, typename... Args>
    auto bind_instance(R (C::* fn)(Args...), const std::shared_ptr<C>& inst)
    {
        return sol::as_function([weakInst = static_cast<std::weak_ptr<C>>(inst), fn](Args&&... args)
        {
            if (weakInst.expired())
                throw std::runtime_error("Function owner was destroyed");
            const auto inst = weakInst.lock();
            return (inst.get()->*fn)(std::forward<Args>(args)...);
        });
    }
}
