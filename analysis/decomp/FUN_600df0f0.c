// 600df0f0  FUN_600df0f0  size=196 bytes
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   600d3618 FUN_600d3618
//   600df0c0 FUN_600df0c0
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   6013d3d8 thunk_EXT_FUN_0000b4c2


undefined4 FUN_600df0f0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  bool bVar8;
  
  iVar6 = param_1 + 0xbc;
  thunk_EXT_FUN_0000b4c2(iVar6);
  if (*(int *)(param_1 + 0x150) == param_2) {
    uVar4 = 0;
LAB_600df110:
    thunk_EXT_FUN_00007d10(iVar6);
  }
  else {
    cVar7 = *(char *)(param_1 + 0x158);
    *(int *)(param_1 + 0x150) = param_2;
    if (cVar7 != '\0') {
      if (*(int *)(param_1 + 0x14c) == 0) {
        thunk_EXT_FUN_00007a2c(*(undefined4 *)(param_1 + 0x80),3,0,0,10);
        uVar3 = *(uint *)(param_1 + 0x150);
        uVar5 = *(uint *)(param_1 + 0x154);
        uVar1 = FUN_600d3618();
        bVar8 = !CARRY4(uVar3,uVar5);
        if (!CARRY4(uVar3,uVar5)) {
          bVar8 = uVar3 + uVar5 <= uVar1;
        }
        if (!bVar8) {
          iVar2 = (uVar5 + uVar3) - uVar1;
          if (iVar2 == 0) {
            uVar4 = 3;
          }
          else {
            iVar2 = thunk_EXT_FUN_00007a2c(*(undefined4 *)(param_1 + 0x80),4,iVar2,0,10);
            if (iVar2 == 0) {
              uVar4 = 4;
            }
            else {
              uVar4 = 0;
            }
          }
          goto LAB_600df110;
        }
      }
      else {
        cVar7 = '\0';
      }
    }
    thunk_EXT_FUN_00007d10(iVar6);
    if (cVar7 != '\0') {
      FUN_600df0c0(param_1,param_1 + 0x7c);
    }
    uVar4 = 0;
  }
  return uVar4;
}


