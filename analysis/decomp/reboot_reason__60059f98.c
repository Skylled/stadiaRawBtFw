// 60059f98  reboot_reason__60059f98  size=108 bytes
// src: reboot_reason.cc
// --- callers ---
//   60051240 main__60051240
//   6005b1c0 application_state__6005b1c0
// --- callees ---
//   6010165c FUN_6010165c
//   60059f00 snvs__60059f00
//   60059eb8 FUN_60059eb8


/* src: reboot_reason.cc */

int * reboot_reason__60059f98(int *param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int local_28 [5];
  
  uVar1 = DAT_6005a004;
  iVar3 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  do {
    cVar2 = snvs__60059f00(uVar1,iVar3,local_28 + iVar3);
    if (cVar2 != '\0') {
      return param_1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  if (local_28[0] < 0) {
    *param_1 = local_28[0] + -0x80000000;
    *(byte *)(param_1 + 1) = (byte)local_28[1] & 1;
    *(byte *)((int)param_1 + 5) = (byte)((uint)(local_28[1] << 0x1e) >> 0x1f);
    *(byte *)((int)param_1 + 6) = (byte)((uint)(local_28[1] << 0x1d) >> 0x1f);
    if ((param_2 == 0) && (cVar2 = FUN_60059eb8(0,0,0), cVar2 != '\0')) {
      FUN_6010165c(0x28,DAT_6005a00c,0x36,DAT_6005a008);
    }
  }
  return param_1;
}


