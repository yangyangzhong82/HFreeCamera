
#include <unordered_set>
class Player;


class FreeCameraManager {
public:
    std::unordered_set<unsigned long long> FreeCamList;
    static FreeCameraManager&              getInstance() {
        static FreeCameraManager instance;
        return instance;
    }
    static void DisableFreeCamera(Player* pl);
    static void EnableFreeCamera(Player* pl);
    static void freecameraHook(bool enable);
};