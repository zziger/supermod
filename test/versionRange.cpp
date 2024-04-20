#include <gtest/gtest.h>
#include <semver/semver.hpp>
#include <utils/VersionRange.h>

TEST(VersionRange, ShouldCheckRangesCorrectly)
{
    const auto range = VersionRange::Parse(">1.0.0 <2.0.0 || =3.0.0 || >=4.0.0");
    EXPECT_FALSE(range.Match(semver::version::parse("1.0.0")));
    EXPECT_TRUE(range.Match(semver::version::parse("1.0.1")));
    EXPECT_TRUE(range.Match(semver::version::parse("1.1.0")));
    EXPECT_TRUE(range.Match(semver::version::parse("1.9.9")));
    EXPECT_FALSE(range.Match(semver::version::parse("2.0.0")));
    EXPECT_TRUE(range.Match(semver::version::parse("3.0.0")));
    EXPECT_FALSE(range.Match(semver::version::parse("3.0.1")));
    EXPECT_TRUE(range.Match(semver::version::parse("4.0.0")));
    EXPECT_TRUE(range.Match(semver::version::parse("4.0.1")));
}

TEST(VersionRange, ShouldCheckRangesWithImplicitOperator)
{
    const auto range = VersionRange::Parse("1.0.0"); // no op is >=
    EXPECT_FALSE(range.Match(semver::version::parse("0.9.9")));
    EXPECT_TRUE(range.Match(semver::version::parse("1.0.0")));
    EXPECT_TRUE(range.Match(semver::version::parse("1.0.1")));
}

TEST(VersionRange, ShouldThrowOnInvalidFormat)
{
    EXPECT_THROW(VersionRange::Parse("!Rsa"), std::runtime_error);
}

TEST(VersionRange, ShouldWorkWithPartialVersions)
{
    const auto range = VersionRange::Parse(">=1.0 <3");
    EXPECT_TRUE(range.Match(semver::version::parse("1.0.0")));
    EXPECT_TRUE(range.Match(semver::version::parse("1.0.1")));
    EXPECT_TRUE(range.Match(semver::version::parse("2.9.9")));
    EXPECT_FALSE(range.Match(semver::version::parse("3.0.0")));
}

TEST(VersionRange, ShouldWorkWithVPrefix)
{
    const auto range = VersionRange::Parse(">=v1.0.0 <v3.0.0");
    EXPECT_TRUE(range.Match(semver::version::parse("1.0.0")));
    EXPECT_TRUE(range.Match(semver::version::parse("1.0.1")));
    EXPECT_TRUE(range.Match(semver::version::parse("2.9.9")));
    EXPECT_FALSE(range.Match(semver::version::parse("3.0.0")));
}

TEST(VersionRange, ShouldMatchEmptyString)
{
    const auto range = VersionRange::Parse("");
    EXPECT_TRUE(range.Match(semver::version::parse("1.0.0")));
    EXPECT_TRUE(range.Match(semver::version::parse("5.0.0")));
}
