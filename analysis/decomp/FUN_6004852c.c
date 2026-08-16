// 6004852c  FUN_6004852c  size=74 bytes
// --- callers ---
//   60043608 FUN_60043608
//   600426c0 FUN_600426c0
// --- callees ---
//   60047290 queue__60047290


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6004852c(int param_1)

{
  int iVar1;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 *puStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined1 uStack_8c;
  undefined1 uStack_8b;
  undefined1 auStack_8a [134];
  
  iVar1 = queue__60047290(*(undefined4 *)(param_1 + 0x50),0,0);
  if (iVar1 != 1) {
    uStack_a0 = _DAT_60048578;
    uStack_9c = 0x21;
    puStack_98 = auStack_8a;
    uStack_94 = 0x80;
    uStack_90 = 0;
    uStack_8c = 0;
    uStack_8b = 0;
    auStack_8a[0] = 0;
    func_0x6004c104(&puStack_98,_DAT_6004857c);
    func_0x6004be44(&uStack_a0);
  }
  return;
}


