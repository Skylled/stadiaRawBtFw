// 6005e020  power_rpcs__6005e020  size=228 bytes
// src: power_rpcs.cc
// --- callers ---
// --- callees ---
//   600cdcc4 FUN_600cdcc4
//   600cc3cc FUN_600cc3cc
//   601019da FUN_601019da
//   60101aa4 FUN_60101aa4
//   600df072 FUN_600df072
//   60101a80 FUN_60101a80
//   60050c18 FUN_60050c18
//   6010165c FUN_6010165c


/* src: power_rpcs.cc */

uint power_rpcs__6005e020(int param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined2 *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 local_57;
  undefined2 local_56;
  undefined1 local_54;
  
  iVar6 = DAT_6005e104;
  uVar5 = DAT_6005e10c;
  if (*(char *)(DAT_6005e104 + 0x158) == '\0') {
    uVar5 = DAT_6005e108;
  }
  FUN_6010165c(0x14,DAT_6005e110,0x1c,DAT_6005e114,uVar5,*(undefined4 *)(DAT_6005e104 + 0x150));
  local_64 = &local_56;
  local_56 = 0x5d5b;
  local_60 = 0x3b;
  local_58 = 0;
  local_57 = 0;
  local_54 = 0;
  local_5c = 2;
  uVar2 = FUN_600df072(iVar6,&local_64);
  if ((uVar2 & 0xff) == 0) {
    piVar3 = (int *)FUN_60101a80(*(undefined4 *)(param_1 + 0x14));
    cVar1 = *(char *)(iVar6 + 0x158);
    iVar7 = piVar3[2];
    iVar4 = FUN_600cc3cc(piVar3,DAT_6005e118);
    if (iVar4 != 0) {
      uVar5 = DAT_6005e11c;
      if (cVar1 == '\0') {
        uVar5 = DAT_6005e120;
      }
      uVar5 = FUN_600cdcc4(*piVar3 + piVar3[2],piVar3[1] - piVar3[2],uVar5);
      FUN_601019da(piVar3,uVar5,iVar7,0x7d);
    }
    uVar2 = (uint)*(byte *)((int)piVar3 + 0xd);
    if (uVar2 == 0) {
      iVar4 = FUN_60101aa4(piVar3,DAT_6005e124,&local_64);
      uVar2 = (uint)*(byte *)(iVar4 + 0xd);
      if (uVar2 == 0) {
        uVar5 = *(undefined4 *)(iVar6 + 0x150);
        iVar4 = piVar3[2];
        iVar6 = FUN_600cc3cc(piVar3,DAT_6005e128);
        if (iVar6 != 0) {
          uVar5 = FUN_60050c18(uVar5,0,piVar3[2] + *piVar3,piVar3[1] - piVar3[2]);
          FUN_601019da(piVar3,uVar5,iVar4,0x7d);
        }
        uVar2 = (uint)*(byte *)((int)piVar3 + 0xd);
      }
    }
  }
  return uVar2;
}


