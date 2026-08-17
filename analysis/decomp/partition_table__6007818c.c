// 6007818c  partition_table__6007818c  size=64 bytes
// src: partition_table.h
// --- callers ---
//   60078340 firmware_image_upload__60078340
//   600db3b6 FUN_600db3b6
// --- callees ---
//   60101740 FUN_60101740
//   600ce2a0 FUN_600ce2a0


/* src: partition_table.h */

int partition_table__6007818c(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_a8 [156];
  
  if (param_2 == 0) {
    FUN_600ce2a0(auStack_a8,DAT_600781d0,DAT_600781cc,0x56);
    FUN_60101740(auStack_a8);
  }
  iVar2 = 0;
  while( true ) {
    if (param_1[1] == iVar2) {
      return 0;
    }
    piVar1 = *(int **)(*param_1 + iVar2 * 4);
    if (*(byte *)(*piVar1 + 8) == param_2) break;
    iVar2 = iVar2 + 1;
  }
  return piVar1[1];
}


