// 6006180c  info__6006180c  size=62 bytes
// src: info.cc
// --- callers ---
//   6006185c FUN_6006185c
//   60077140 FUN_60077140
//   6005b150 application_state__6005b150
// --- callees ---
//   60083f98 FUN_60083f98
//   600678ec binary_build_metadata__600678ec
//   6010165c FUN_6010165c
//   600653f0 FUN_600653f0


/* src: info.cc */

undefined4 info__6006180c(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_600653f0();
  iVar2 = FUN_60083f98();
  if (iVar2 == 0) {
    uVar3 = 0x38;
    uVar1 = DAT_6006184c;
  }
  else {
    iVar2 = binary_build_metadata__600678ec(uVar1,iVar2);
    if (iVar2 != 0) {
      return *(undefined4 *)(iVar2 + 0x14);
    }
    uVar3 = 0x3e;
    uVar1 = DAT_60061858;
  }
  FUN_6010165c(0x14,DAT_60061850,uVar3,uVar1);
  FUN_6010165c(0x14,DAT_60061850,0x73,DAT_60061854);
  return 0;
}


