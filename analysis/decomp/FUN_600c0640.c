// 600c0640  FUN_600c0640  size=78 bytes
// --- callers ---
//   600f0662 FUN_600f0662
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600c1a34 FUN_600c1a34


void FUN_600c0640(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 local_d;
  undefined4 local_c;
  
  if (((*(char *)(DAT_600c0690 + 0x23) == '\x01') && (*(char *)(DAT_600c0690 + 0x2a) == '\x02')) &&
     (local_d = param_2, local_c = param_1, iVar1 = thunk_EXT_FUN_0000b554(DAT_600c0694,param_1,6),
     iVar1 == 0)) {
    *(undefined1 *)(DAT_600c0690 + 0x2a) = 0;
    FUN_600c1a34(DAT_600c0690,0x15,&local_d);
  }
  return;
}


