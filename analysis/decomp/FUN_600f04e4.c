// 600f04e4  FUN_600f04e4  size=110 bytes
// --- callers ---
//   600c288c FUN_600c288c
//   600c2b3c FUN_600c2b3c
// --- callees ---
//   600b218c FUN_600b218c
//   600f048a FUN_600f048a
//   6009ff18 FUN_6009ff18


undefined1 FUN_600f04e4(undefined4 param_1,undefined1 param_2)

{
  short sVar1;
  int iVar2;
  undefined1 local_9;
  
  sVar1 = FUN_600f048a(param_1,param_2);
  local_9 = 0;
  iVar2 = FUN_6009ff18(param_1);
  if ((iVar2 == 0) || (*(char *)(iVar2 + 0xee) != '\x01')) {
    if (sVar1 == -1) {
      local_9 = 7;
    }
    else {
      iVar2 = FUN_600b218c(sVar1,0x13);
      if (iVar2 == 0) {
        local_9 = 3;
      }
    }
  }
  else {
    *(undefined1 *)(iVar2 + 0xee) = 2;
  }
  return local_9;
}


