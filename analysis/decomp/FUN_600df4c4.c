// 600df4c4  FUN_600df4c4  size=40 bytes
// --- callers ---
// --- callees ---
//   6005d9a8 gatt_service_handle__6005d9a8


undefined4 FUN_600df4c4(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  
  local_18 = param_1;
  puStack_14 = param_2;
  uStack_10 = param_3;
  puVar1 = (undefined4 *)gatt_service_handle__6005d9a8();
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 9;
  }
  else {
    local_18 = *param_2;
    puStack_14 = (undefined4 *)param_2[1];
    uVar2 = (**(code **)*puVar1)(puVar1,param_1,&local_18);
  }
  return uVar2;
}


