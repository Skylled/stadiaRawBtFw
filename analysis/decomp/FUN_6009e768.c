// 6009e768  FUN_6009e768  size=94 bytes
// --- callers ---
// --- callees ---
//   600f1592 FUN_600f1592
//   600aa3cc FUN_600aa3cc


void FUN_6009e768(void)

{
  byte *pbVar1;
  code *pcVar2;
  
  pbVar1 = DAT_6009e7c8;
  pcVar2 = *(code **)(DAT_6009e7c8 + 0xcc);
  FUN_600aa3cc(DAT_6009e7c8 + 0xd0);
  *pbVar1 = *pbVar1 & 0x7f;
  pbVar1[200] = 0;
  pbVar1[0xc9] = 0;
  pbVar1[0xca] = 0;
  pbVar1[0xcb] = 0;
  pbVar1[0xcc] = 0;
  pbVar1[0xcd] = 0;
  pbVar1[0xce] = 0;
  pbVar1[0xcf] = 0;
  if ((*pbVar1 & 0xf0) == 0) {
    FUN_600f1592();
  }
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(DAT_6009e7cc);
  }
  return;
}


