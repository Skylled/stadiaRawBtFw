// 600d44b0  FUN_600d44b0  size=66 bytes
// --- callers ---
// --- callees ---
//   6004cb28 FUN_6004cb28
//   6005d9a8 gatt_service_handle__6005d9a8
//   601024d8 FUN_601024d8


void FUN_600d44b0(int param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined1 *local_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [20];
  undefined1 local_1c;
  
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  puVar1 = (undefined4 *)gatt_service_handle__6005d9a8();
  if (puVar1 != (undefined4 *)0x0) {
    pcVar2 = *(code **)*puVar1;
    FUN_601024d8(auStack_30,uVar3,0x14);
    local_1c = 0;
    uStack_34 = FUN_6004cb28(auStack_30);
    local_38 = auStack_30;
    (*pcVar2)(puVar1,param_1,&local_38);
  }
  return;
}


