#pragma once
#include "EventManager.h"

struct ResolutionChangeEvent final : IEvent<"resolutionChange", ResolutionChangeEvent> {
	int x;
	int y;

	ResolutionChangeEvent(int x, int y) : x(x), y(y) {}

	void RegisterType(LuaContext* ctx) override {
		ctx->registerMember("x", &ResolutionChangeEvent::x);
		ctx->registerMember("y", &ResolutionChangeEvent::y);
	}
};