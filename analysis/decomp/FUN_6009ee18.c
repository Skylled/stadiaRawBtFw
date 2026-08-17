// 6009ee18  FUN_6009ee18  size=106 bytes
// --- callers ---
//   6009f428 FUN_6009f428
//   6009f2ec FUN_6009f2ec
//   6009f6c0 FUN_6009f6c0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_6009ee18(undefined4 param_1,undefined1 param_2)

{
  int *piVar1;
  
  piVar1 = DAT_6009ee84;
  thunk_EXT_FUN_0000b572((uint)*(byte *)(DAT_6009ee84 + 2) * 6 + *DAT_6009ee84,param_1,6);
  *(undefined1 *)(piVar1[1] + (uint)*(byte *)(piVar1 + 2)) = param_2;
  *(char *)(piVar1 + 2) = (char)piVar1[2] + '\x01';
  *(byte *)(piVar1 + 2) =
       *(byte *)(piVar1 + 2) -
       *(byte *)(DAT_6009ee88 + 0xa6b) * (*(byte *)(piVar1 + 2) / *(byte *)(DAT_6009ee88 + 0xa6b));
  return;
}


