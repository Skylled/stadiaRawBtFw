// 600c1864  FUN_600c1864  size=284 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600aa3cc FUN_600aa3cc
//   600c239c FUN_600c239c
//   6013d168 thunk_EXT_FUN_0000b554
//   6006ddd8 FUN_6006ddd8
//   600aa340 FUN_600aa340
//   600f7c42 FUN_600f7c42


void FUN_600c1864(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  byte *pbVar4;
  byte local_9;
  
  iVar1 = DAT_600c1980;
  pbVar4 = (byte *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
  local_9 = *pbVar4;
  if ((local_9 < 0xf) && (local_9 != 0)) {
    if ((local_9 == 1) || (local_9 == 0xb)) {
      if (*(char *)(DAT_600c1980 + 0x23) == '\0') {
        uVar2 = FUN_600f7c42(param_1);
        *(undefined1 *)(iVar1 + 0x26) = uVar2;
        thunk_EXT_FUN_0000b572(iVar1 + 0x1d,param_1,6);
      }
      else {
        iVar3 = thunk_EXT_FUN_0000b554(param_1,DAT_600c1980 + 0x1d,6);
        if (iVar3 != 0) {
          FUN_6006ddd8(param_2,DAT_600c1984,0xb9);
          FUN_600c239c(param_1);
          return;
        }
      }
    }
    iVar3 = thunk_EXT_FUN_0000b554(param_1,iVar1 + 0x1d,6);
    if (iVar3 == 0) {
      FUN_600aa3cc(iVar1 + 4);
      FUN_600aa340(iVar1 + 4,0x32,0x1e);
      if (((local_9 == 3) && ((*(byte *)(iVar1 + 0x191) & 8) != 0)) &&
         ((*(byte *)(iVar1 + 0x192) & 8) != 0)) {
        local_9 = 0xf;
      }
      *(byte *)(iVar1 + 0x1fc) = local_9;
      *(char *)(iVar1 + 0x1fd) = (char)*(undefined2 *)(param_2 + 2);
      FUN_600c1a34(iVar1,local_9,pbVar4 + 1);
    }
    FUN_6006ddd8(param_2,DAT_600c1984,0xda);
  }
  else {
    FUN_6006ddd8(param_2,DAT_600c1984,0xa7);
  }
  return;
}


