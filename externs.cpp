#include <cstdint>
#include <string>
#include <memory>

struct CTinyJS;
struct BlockSource;
struct LocalPlayer;
struct MinecraftClient;
struct FullBlock;
struct BlockPos;
struct Entity;
struct Level;
struct GuiData;
struct Vec3;
struct PlayerInventoryProxy;
struct Item;
struct ItemInstance;
struct InventorySlot;
struct TextureAtlas;

//the JavaScript interpreter
CTinyJS* interpreter;

//various helpers
bool PREVENTDEFAULT = false;
bool GRAPHICS_LOADED = false;
bool SCRIPTS_NEED_INIT;

//pointers
LocalPlayer* MCPE_localplayer;
MinecraftClient* MCPE_client;
uintptr_t** CreativeMode$vtable;
uintptr_t** SurvivalMode$vtable;
Item** Item$mItems;

//function pointers
void (*Level$explode)(Level*, BlockSource*, Entity*, const Vec3&, float, bool, bool, float);
bool (*BlockSource$setBlockAndData)(BlockSource*, int, int, int, FullBlock, int);
FullBlock (*BlockSource$getBlockAndData)(BlockSource*, const BlockPos&);
uint64_t& (*Entity$getUniqueID)(Entity*);
Entity* (*Level$fetchEntity)(Level*, uint64_t, bool);
void (*GuiData$addMessage)(GuiData*, const std::string&, const std::string&, int, bool);
InventorySlot (*PlayerInventoryProxy$getSelectedSlot)(PlayerInventoryProxy*);
const ItemInstance& (*PlayerInventoryProxy$getItem)(PlayerInventoryProxy*, int, int);
void (*PlayerInventoryProxy$add)(PlayerInventoryProxy*, ItemInstance&, bool);
int (*PlayerInventoryProxy$getLinkedSlotsCount)(PlayerInventoryProxy*);
int (*PlayerInventoryProxy$getLinkedSlot)(PlayerInventoryProxy*, int);
void (*PlayerInventoryProxy$replaceSlot)(PlayerInventoryProxy*, int, const ItemInstance&);
void (*PlayerInventoryProxy$clearSlot)(PlayerInventoryProxy*, int, int);
Item* (*Item$Item)(Item*, const std::string&, short);
ItemInstance* (*ItemInstance$fromItem)(ItemInstance*, Item*);
void (*ItemInstance$operator_equals)(ItemInstance*, const ItemInstance&);
