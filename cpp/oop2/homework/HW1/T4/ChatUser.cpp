#include "ChatUser.h"

    void ChatUser:: addFriend(ChatUser* user){
        if(user == nullptr){
            return;
        }
        bool isFriend = false;
        for(int i=0;i<this->friends.size();i++){
            if(this->friends[i]->name==user->name){
                isFriend = true;
            }
        }
        if(isFriend){
            std::cout << this->name << " and " << user->name << " are already friends" << '\n';
            return;
        }
        else{
            friends.push_back(user);
            std::cout << this->name <<" -> add friend -> " << user -> name << '\n';
        }
    }
    void ChatUser:: removeFriend(ChatUser* user){
        if(user == nullptr) return;
        
        // 需要先遍历确认是否是好友
        bool isFriend = false;
        for(auto* f : friends){
            if(f->getName() == user->getName()){
                isFriend = true;
                break;
            }
        }
    
        if(!isFriend){
            std::cout << name << " and " << user->getName() << " are not yet friends\n";
            return;
        }
    
        // 正确删除所有匹配项（原代码只删除了第一个匹配项）
        friends.erase(std::remove_if(friends.begin(), friends.end(),
            [&](ChatUser* u) { return u->getName() == user->getName(); }),
            friends.end());
            
        std::cout << name << " -> remove friend -> " << user->getName() << '\n';
    }
    void ChatUser:: sendMessage(ChatUser* user, std::string message){
        if(user == nullptr){
            return;
        }
        std::cout << this->name << " -> send message -> " << user->name << " : " << message << '\n';
        user->receiveMessage(this, message);
    }
    void ChatUser:: receiveMessage(ChatUser* user, std::string message){
        if(user == nullptr){
            return;
        }
        std::cout << this->name << " -> receive message -> " << user->name << " : " << message << '\n';
        bool isFind = false;
        for(int i = 0;i < this->messageQueue.size();i++){
            if(this->messageQueue[i].first->name == user->name){
                this->messageQueue[i].second.push_back(message);
                isFind = true;
            }
           
        }
        if(!isFind){
            // 使用emplace_back代替push_back+临时变量
            messageQueue.emplace_back(user, std::vector<std::string>{message});
        }
    }
    void ChatUser:: showMessage() {
        std::cout << "Chat " << this->name << ":" << '\n';
        for (auto& entry : messageQueue) {
            std::cout << ">> From " << entry.first->getName() << ":" << '\n';
            for (auto& msg : entry.second) {
                std::cout << ">> " << msg << '\n';
            }
        }
    }
    void ChatUser:: showFriends(){
        std::cout << name << "'s friend:";
        
        // 添加空格分隔且末尾无空格
        for(size_t i = 0; i < friends.size(); ++i){
            std::cout << " " << friends[i]->getName();
        }
        std::cout << '\n';  // 统一使用\n换行
    }

