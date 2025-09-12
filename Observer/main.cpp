#include <bits/stdc++.h>
#include "Observer.hpp"

using namespace std;

int main(){
    user* u1 = new user(1);
    user* u2 = new user(2);
    user* u3 = new user(3);

    group* youtubeChannel = new group();
    youtubeChannel->subscribe(u1);
    youtubeChannel->subscribe(u2);
    youtubeChannel->subscribe(u3);

    youtubeChannel->notify("Video Posted.");

    youtubeChannel->unsubscribe(u2);

    youtubeChannel->notify("Shorts added.");

    return 0;
}