#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

class Exception {
    public:
        std::string text;
        
        Exception(const std::string& text) : text(text) {}
        virtual ~Exception() {}
};

class UnitIsDeadException : public Exception {
    public:
        UnitIsDeadException(const std::string& text= "Unit is dead.") : Exception(text) {}
        virtual ~UnitIsDeadException() {}
};

class OutOfManaException : public Exception {
    public:
        OutOfManaException(const std::string &text = "No mana left.") : Exception(text) {}
        virtual ~OutOfManaException() {}
};

class NoMagicAffectException : public Exception {
    public:
        NoMagicAffectException(const std::string &text = "No magic allowed.") : Exception(text) {}
        virtual ~NoMagicAffectException() {}
};

class NoSuchSpellException : public Exception {
    public:
        NoSuchSpellException(const std::string &text = "No such spell.") : Exception(text) {}
        virtual ~NoSuchSpellException() {}
};

class UnitHealNotAllowedException : public Exception {
    public:
        UnitHealNotAllowedException(const std::string &text = "Heal not allowed.") : Exception(text) {}
        virtual ~UnitHealNotAllowedException() {}
};

class NotTurnVampireException : public Exception {
    public:
        NotTurnVampireException(const std::string &text = "Turning in Vampire not allowed.") : Exception(text) {}
        virtual ~NotTurnVampireException() {}
};

class NotTurnWerewolfException : public Exception {
    public:
        NotTurnWerewolfException(const std::string &text = "Turning in Werewolf not allowed.") : Exception(text) {}
        virtual ~NotTurnWerewolfException() {}
};

#endif // EXCEPTIONS_H
