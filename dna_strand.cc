#include "dna_strand.hpp"
#include <stdexcept>
DNAstrand::~DNAstrand() {
  Node* current = head_;
  while (current != nullptr) {
    Node* temp = current->next;
    delete current;
    current = temp;
  }
  head_ = nullptr;
  tail_ = nullptr;
}

// counts characters in pattern
int DNAstrand::PatternSize(const char* pattern) {
  int count = 0;
  for (int i = 0; pattern[i] != '\0'; i++) {
    count++;
  }
  return count;
}

// counts nodes in dna linked list
int DNAstrand::StrandSize() {
  Node* current = head_;
  int count = 0;
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

void DNAstrand::SetTail() {
  Node* set_tail = head_;
  while (set_tail != nullptr) {
    if (set_tail->next == nullptr) {
      tail_ = set_tail;
    }
    set_tail = set_tail->next;
  }
}

void DNAstrand::CleanUp(Node* node_before_first_match,
                        Node* ending_node_toconnect,
                        DNAstrand& to_splice_in) {
  if (node_before_first_match != nullptr) {
    node_before_first_match->next = to_splice_in.head_;
  } else
    head_ = to_splice_in.head_;  // edge case at the start
  to_splice_in.tail_->next = ending_node_toconnect;
  to_splice_in.head_ = nullptr;
  to_splice_in.tail_ = nullptr;
}

void DNAstrand::DeletePattern(Node* node_before_first_match,
                              const char* pattern) {
  Node* del = nullptr;
  if (node_before_first_match == nullptr) {
    del = head_;
  } else {
    del = node_before_first_match->next;
  }
  for (int i = 0; i < PatternSize(pattern); i++) {
    Node* next = del->next;
    delete del;
    del = next;
  }
}

void DNAstrand::SpliceIn(const char* pattern, DNAstrand& to_splice_in) {
  if (sizeof(pattern) == 0 || to_splice_in.head_ == nullptr ||
      &to_splice_in == this) {
    return;
  }
  DNAstrand dna;
  Node* current = head_;
  Node* checker = current;  // starts at current node and matches pattern index
  Node* ending_node_toconnect = nullptr;
  Node* node_before_first_match = nullptr;
  Node* before_current = nullptr;
  bool pattern_found = false;
  for (int i = 0; i < StrandSize() - PatternSize(pattern) + 1; i++) {
    checker = current;
    bool flag = true;  // checks if checker.data == pattern[j]
    for (int j = 0; j < PatternSize(pattern); j++) {
      if (checker->data != pattern[j]) {
        flag = false;
        break;
      }
      checker = checker->next;
    }
    if (flag) {
      pattern_found = true;
      node_before_first_match = before_current;
      ending_node_toconnect = checker;
    }
    before_current = current;
    current = current->next;
  }
  if (!pattern_found) {
    throw std::runtime_error("pattern not found");
  }

  DeletePattern(node_before_first_match, pattern);
  CleanUp(node_before_first_match, ending_node_toconnect, to_splice_in);
  SetTail();
}

void DNAstrand::PushBack(char data) {
  Node* node = new Node(data);
  if (head_ == nullptr) {
    head_ = node;
    return;
  }
  Node* current = head_;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = node;
}

/* void DNAstrand::Print() {
  Node* current = head_;
  while (current != nullptr) {
    if (current->next == nullptr) {
      tail_ = current;
    }
    std::cout << current->data << " -> " << "current ad: " << current << "
current next ad: " << current->next << "\n"; current = current->next;
  }
  std::cout << '\n' << "tail is: " << tail_->data << "    ";
} */
