// 600aa800  FUN_600aa800  size=82 bytes
// --- callers ---
//   600f32aa FUN_600f32aa
// --- callees ---
//   6006ddd8 FUN_6006ddd8
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d9250 FUN_600d9250


void FUN_600aa800(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = FUN_600d9250(param_1 + 0x14);
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        (**(code **)(iVar1 + 4))(0,param_1,0,0);
      }
      FUN_6006ddd8(iVar1,DAT_600aa854,0x96);
    }
  } while (iVar1 != 0);
  thunk_EXT_FUN_0000b5ba(param_1,0,0x20);
  return;
}


