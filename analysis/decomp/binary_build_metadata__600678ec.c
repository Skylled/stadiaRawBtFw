// 600678ec  binary_build_metadata__600678ec  size=194 bytes
// src: binary_build_metadata.cc
// --- callers ---
//   60078340 firmware_image_upload__60078340
//   6006180c info__6006180c
// --- callees ---
//   6010165c FUN_6010165c


/* src: binary_build_metadata.cc */

int * binary_build_metadata__600678ec(int *param_1,uint param_2)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint local_14;
  
  if ((param_2 == 0x13) || (param_2 - 1 < 3)) {
    for (iVar7 = 0; param_1[1] != iVar7; iVar7 = iVar7 + 1) {
      piVar5 = *(int **)(*param_1 + iVar7 * 4);
      if (*(byte *)(*piVar5 + 8) == param_2) {
        piVar5 = (int *)piVar5[1];
        if (piVar5 != (int *)0x0) {
          local_14 = 0;
          cVar1 = (**(code **)(*piVar5 + 4))(piVar5,&local_14,0,4,param_1);
          if (cVar1 == '\0') {
            if (local_14 == DAT_600679c0) {
              iVar7 = 0x1400;
            }
            else {
              iVar7 = 0x400;
            }
            piVar3 = (int *)piVar5[1];
            piVar5 = (int *)(**(code **)(*piVar3 + 0x20))
                                      (piVar3,iVar7 + piVar3[1] * (piVar5[2] - piVar3[5]) +
                                                      piVar3[4]);
            if (piVar5 != (int *)0x0) {
              if (((*piVar5 == DAT_600679c8) && (piVar5[0x3f] == DAT_600679cc)) &&
                 (piVar5[2] == 0x100)) {
                return piVar5;
              }
              uVar4 = 0x47;
              uVar2 = 0x14;
              uVar6 = DAT_600679d0;
              goto LAB_60067900;
            }
            uVar2 = 0x41;
            uVar6 = DAT_600679c4;
          }
          else {
            uVar2 = 0x37;
            uVar6 = DAT_600679bc;
          }
          FUN_6010165c(0x28,DAT_600679b4,uVar2,uVar6);
          return (int *)0x0;
        }
        break;
      }
    }
    uVar4 = 0x2b;
    uVar6 = DAT_600679b8;
  }
  else {
    uVar4 = 0x26;
    uVar6 = DAT_600679b0;
  }
  uVar2 = 0x28;
  local_14 = param_2;
LAB_60067900:
  FUN_6010165c(uVar2,DAT_600679b4,uVar4,uVar6);
  return (int *)0x0;
}


