#include "ll/api/command/CommandHandle.h"
#include "ll/api/command/CommandRegistrar.h"
#include "mc/server/commands/CommandOrigin.h"
#include "mc/server/commands/CommandOutput.h"
#include "mc/server/commands/CommandPermissionLevel.h"
#include "mc/world/actor/player/Player.h"
#include "mc/server/commands/PlayerCommandOrigin.h"
#include "FreeCamera.h"
struct FreeCameraOn {};
struct FreeCameraOff {};

using ll::command::CommandHandle;
using ll::command::CommandRegistrar;
void RegisterCommand() {

    auto& registrar = CommandRegistrar::getInstance();
    auto& command   = registrar.getOrCreateCommand("fc", "自由视角开关", CommandPermissionLevel::Any);
    command.overload().execute([&](CommandOrigin const& origin, CommandOutput& output) {
        auto* player = static_cast<Player*>(static_cast<PlayerCommandOrigin const&>(origin).getEntity());
        if (!player) {
            output.error("该命令只能由玩家执行。");
            return;
        }
            auto guid = player->getNetworkIdentifier().mGuid.g;
            if (!FreeCameraManager::getInstance().FreeCamList.count(guid)) {
                FreeCameraManager::EnableFreeCamera(player);
                return output.success("自由视角已开启");
            } else {
            FreeCameraManager::DisableFreeCamera(player);
            return output.success("自由视角已关闭");
            }
        
    });
}