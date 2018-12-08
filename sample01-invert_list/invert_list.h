// https://github.com/v-gr-dev18/2018-12-04_samples/blob/master/sample01-invert_list/invert_list.h
// инвертирование однонаправленного списка
//============================================================================================================
#ifndef _INVERT_LIST_H_
#define _INVERT_LIST_H_

template <typename T, class ListNode>
void invert_list(ListNode* &first) {
    auto old_first = first;
    first = nullptr;
    while (old_first) {
        auto current = old_first;
        old_first = old_first->next;
        current->next = first;
        first = current;
    }
}
#endif
