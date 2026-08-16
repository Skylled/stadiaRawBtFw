// 60098284  FUN_60098284  size=240 bytes
// --- callers ---
//   6009f60c FUN_6009f60c
//   6009f5d0 FUN_6009f5d0
//   600eff9c FUN_600eff9c
//   60098668 FUN_60098668
//   6009837c FUN_6009837c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600a1394 FUN_600a1394


undefined1 FUN_60098284(char param_1,uint param_2)

{
  undefined1 *puVar1;
  undefined1 local_24 [20];
  undefined1 *local_10;
  undefined1 local_9;
  
  local_9 = 0;
  local_10 = local_24;
  thunk_EXT_FUN_0000b5ba(local_24,0,0x14);
  if (((param_1 == '\0') || ((param_2 & *(uint *)(DAT_60098374 + 0xc0)) == 0)) &&
     ((param_1 != '\0' || ((param_2 & *(uint *)(DAT_60098374 + 0xc0)) != 0)))) {
    puVar1 = local_10 + 1;
    *local_10 = 1;
    local_10 = puVar1;
    if (param_1 == '\0') {
      *(uint *)(DAT_60098374 + 0xc0) = ~param_2 & *(uint *)(DAT_60098374 + 0xc0);
    }
    else {
      *(uint *)(DAT_60098374 + 0xc0) = param_2 | *(uint *)(DAT_60098374 + 0xc0);
    }
    puVar1 = local_10 + 1;
    *local_10 = (char)*(undefined4 *)(DAT_60098374 + 0xc0);
    local_10 = puVar1;
    puVar1 = local_10 + 1;
    *local_10 = (char)((uint)*(undefined4 *)(DAT_60098374 + 0xc0) >> 8);
    local_10 = puVar1;
    puVar1 = local_10 + 1;
    *local_10 = (char)((uint)*(undefined4 *)(DAT_60098374 + 0xc0) >> 0x10);
    local_10 = puVar1;
    puVar1 = local_10 + 1;
    *local_10 = (char)((uint)*(undefined4 *)(DAT_60098374 + 0xc0) >> 0x18);
    local_10 = puVar1;
    local_9 = FUN_600a1394(0xfce9,5,local_24,DAT_60098378);
  }
  return local_9;
}


