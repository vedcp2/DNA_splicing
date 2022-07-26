#ifndef DNA_STRAND_HPP
#define DNA_STRAND_HPP

#include "node.hpp"

class DNAstrand {
public:
  DNAstrand() = default;
  DNAstrand(const DNAstrand& rhs) = delete;
  DNAstrand& operator=(const DNAstrand& rhs) = delete;
  ~DNAstrand();

  void SpliceIn(const char* pattern, DNAstrand& to_splice_in);
  void PushBack(char data);
  //void Print();
  int StrandSize();
  int PatternSize(const char* pattern);
  void SetTail();
  void CleanUp(Node* node_before_first_match, Node* ending_node_toconnect, DNAstrand& to_splice_in);
  void DeletePattern(Node* node_before_first_match, const char* pattern);

private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif