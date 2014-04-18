//  File Name        : tree.hpp
//  Description      : Abstract syntax tree definitions
//
//  Revision History :
//      Albert Ng   Apr 16 2014     Initial Revision

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <vector>

class NProgram;
class NAlphabetDecl;
class NCharacterDecl;
class NIdentifier;
class NIntConst;

typedef std::vector<NCharacterDecl*> CharacterDeclList;

class Node {
  public:
    virtual void dump(std::ostream& stream, int depth) = 0;
};

class NProgram : public Node {
  public:
    NAlphabetDecl* alphabet_decl;
    NProgram(NAlphabetDecl* alphabet_decl) : alphabet_decl(alphabet_decl) {}
    void dump(std::ostream& stream, int depth);
};

class NAlphabetDecl : public Node {
  public:
    CharacterDeclList* characters;
    NAlphabetDecl(CharacterDeclList* characters) : characters(characters) {}
    void dump(std::ostream& stream, int depth);
};
    
class NCharacterDecl : public Node {
  public:
    NIdentifier* id;
    NIntConst* value;
    NCharacterDecl(NIdentifier* id, NIntConst* value) : id(id), value(value) {}
    NCharacterDecl(NIdentifier* id) : id(id), value(NULL) {}
    void dump(std::ostream& stream, int depth);
};

class NIdentifier : public Node {
  public:
    std::string* name;
    NIdentifier(std::string* name) : name(name) {}
    void dump(std::ostream& stream, int depth);
};

class NIntConst : public Node {
  public:
    int value;
    NIntConst(int value) : value(value) {}
    void dump(std::ostream& stream, int depth);
};

#endif // TREE_H_
