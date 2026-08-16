// 6009496c  FUN_6009496c  size=194 bytes
// --- callers ---
//   600ee89c FUN_600ee89c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600fa27a FUN_600fa27a
//   6006ddd8 FUN_6006ddd8
//   600fa298 FUN_600fa298
//   6006dbac FUN_6006dbac


undefined1 FUN_6009496c(undefined2 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20 [2];
  undefined2 local_1c;
  undefined2 local_c;
  undefined1 local_9;
  
  local_c = 2;
  local_9 = 0x85;
  thunk_EXT_FUN_0000b5ba(local_20,0,0x14);
  local_20[0] = 2;
  local_1c = 7;
  uVar1 = FUN_6006dbac(0x2ee,DAT_60094a30,0x38c);
  *(undefined4 *)(DAT_60094a34 + 0x5c0) = uVar1;
  if (*(int *)(DAT_60094a34 + 0x5c0) != 0) {
    local_24 = 1;
    local_22 = 4;
    FUN_600fa27a(*(undefined4 *)(DAT_60094a34 + 0x5c0),0x2ee,1,local_20,local_c,&local_24);
    iVar2 = FUN_600fa298(param_2 + 1,*(undefined4 *)(DAT_60094a34 + 0x5c0),DAT_60094a38);
    if (iVar2 == 0) {
      FUN_6006ddd8(*(undefined4 *)(DAT_60094a34 + 0x5c0),DAT_60094a30,0x395);
      *(undefined4 *)(DAT_60094a34 + 0x5c0) = 0;
    }
    else {
      *(undefined2 *)(DAT_60094a34 + 0x5c4) = param_1;
      local_9 = 0;
    }
  }
  return local_9;
}


