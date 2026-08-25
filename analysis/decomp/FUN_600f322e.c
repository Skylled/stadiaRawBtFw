// 600f322e  FUN_600f322e  size=124 bytes
// --- callers ---
//   600aae30 FUN_600aae30
//   600f3318 FUN_600f3318
//   600f32aa FUN_600f32aa
// --- callees ---
//   600ab620 FUN_600ab620
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600aa8a4 FUN_600aa8a4


undefined1 FUN_600f322e(int param_1)

{
  int iVar1;
  undefined2 local_2a;
  undefined1 local_28 [2];
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_20;
  undefined2 local_1c;
  undefined1 local_9;
  
  local_2a = 0;
  local_9 = 0;
  iVar1 = FUN_600aa8a4(param_1,&local_2a,param_1 + 8);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b5ba(local_28,0,0x1c);
    local_20 = 2;
    local_1c = local_2a;
    local_26 = 1;
    local_24 = 0xffff;
    local_28[0] = 0;
    iVar1 = FUN_600ab620(*(undefined2 *)(param_1 + 0xc),1,local_28);
    if (iVar1 == 0) {
      *(undefined2 *)(param_1 + 0xe) = local_2a;
      local_9 = 1;
    }
  }
  return local_9;
}


