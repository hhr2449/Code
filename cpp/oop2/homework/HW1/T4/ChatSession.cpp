#include "ChatSession.h"


void ChatSession::addUser(ChatUser* user) {
    if (!user) return;
    users.push_back(user);
    std::cout << "Add user: " << user->getName() << std::endl;
}

void ChatSession::removeUser(ChatUser* user) {
    if (!user) return;
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i]->getName() == user->getName()) {
            std::cout << "Remove user: " << user->getName() << std::endl;
            users.erase(users.begin() + i);
            return;
        }
    }
}

ChatUser* ChatSession::getUserByName(std::string name) {
    for (auto* u : users) {
        if (u->getName() == name) return u;
    }
    std::cout << name << " not in chat\n";
    return nullptr;
}
