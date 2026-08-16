// 600c1788  FUN_600c1788  size=214 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   600f7c42 FUN_600f7c42
//   6013d168 thunk_EXT_FUN_0000b554


void FUN_600c1788(undefined4 param_1,char param_2,undefined2 param_3,char param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_14 [4];
  int local_c;
  
  local_c = DAT_600c1860;
  local_1c = 0;
  local_18 = 0;
  if (((param_4 != '\x01') &&
      (iVar2 = thunk_EXT_FUN_0000b554(param_1,&local_1c,6,&local_1c,param_3), iVar2 != 0)) &&
     (iVar2 = thunk_EXT_FUN_0000b554(param_1,local_c + 0x1d,6), iVar2 == 0)) {
    if (param_2 == '\0') {
      local_14[0] = param_3;
      FUN_600c1a34(local_c,0x13,local_14);
    }
    else if (*(char *)(local_c + 0x2c) == '\0') {
      *(undefined1 *)(local_c + 0x2c) = 1;
      uVar1 = FUN_600f7c42(param_1);
      *(undefined1 *)(local_c + 0x26) = uVar1;
      *(undefined1 *)(local_c + 0x1b4) = 0xf;
      *(undefined1 *)(local_c + 0x1b5) = *(undefined1 *)(local_c + 0x1b4);
      *(undefined1 *)(local_c + 0x191) = 0;
      *(undefined1 *)(local_c + 0x192) = *(undefined1 *)(local_c + 0x191);
      *(undefined1 *)(local_c + 0x2a) = 1;
      FUN_600c1a34(local_c,0x12,0);
    }
  }
  return;
}


