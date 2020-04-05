//
// Created by ryan on 01.11.19.
//
#include "FunctionalObjects.h"

#include "gtest/gtest.h"


// Tests that the Foo::Bar() method does Abc.
TEST(default, FunctionalObjects_basistest) {
    gen fen(0,0.1);
    auto x = integrate(fen,1000);
    EXPECT_EQ(1,x);
            }


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

