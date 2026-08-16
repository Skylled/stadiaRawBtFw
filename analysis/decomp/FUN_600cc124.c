// 600cc124  FUN_600cc124  size=60 bytes
// --- callers ---
//   601016a2 FUN_601016a2
//   60101740 FUN_60101740
// --- callees ---
//   6005856c FUN_6005856c
//   6005f8c0 FUN_6005f8c0
//   6013cef8 thunk_EXT_FUN_0000737c
//   6013d088 thunk_EXT_FUN_00007734


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_600cc124(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_cr14;
  
  iVar1 = thunk_EXT_FUN_00007734();
  if (((iVar1 == 2) && (iVar1 = FUN_6005856c(), *(char *)(iVar1 + 0xfd) != '\0')) &&
     ((_DAT_e000ed04 & 0x1ff) == 0)) {
    thunk_EXT_FUN_0000737c(10000);
  }
  puVar2 = (undefined4 *)FUN_6005f8c0(param_1,param_2,param_3);
  coprocessor_store(0,in_cr14,puVar2);
  *puVar2 = DAT_600cc174;
  if (puVar2[0x16] != 0) {
    tasks__600ca27c();
  }
  return puVar2;
}


