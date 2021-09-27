//
// Created by l30014168 on 2021/9/27.
//

#include <unity.h>
#include <stdlib.h>
#include "exam-room.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void examRoomTestExample1(void) {
    ExamRoom* obj = examRoomCreate(10);
    TEST_ASSERT_EQUAL_INT(0, examRoomSeat(obj));
    TEST_ASSERT_EQUAL_INT(9, examRoomSeat(obj));
    TEST_ASSERT_EQUAL_INT(4, examRoomSeat(obj));
    TEST_ASSERT_EQUAL_INT(2, examRoomSeat(obj));
    examRoomLeave(obj,4);
    TEST_ASSERT_EQUAL_INT(5, examRoomSeat(obj));
    examRoomFree(obj);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(examRoomTestExample1);
    return UNITY_END();
}