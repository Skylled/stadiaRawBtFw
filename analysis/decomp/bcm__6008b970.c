// 6008b970  bcm__6008b970  size=124 bytes
// src: bcm.c
// --- callers ---
//   600e9b62 FUN_600e9b62
//   600e9a8e FUN_600e9a8e
// --- callees ---
//   600e75c2 FUN_600e75c2
//   600e72fc FUN_600e72fc
//   600e0552 FUN_600e0552
//   600e7706 FUN_600e7706
//   600e7480 FUN_600e7480
//   600e9414 FUN_600e9414


/* src: bcm.c */

undefined4 bcm__6008b970(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = param_2;
  iVar1 = FUN_600e75c2(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_600e7706(param_2);
    if (iVar1 == 0) {
      uVar2 = 0x68;
      uVar5 = 0xa9;
    }
    else if (*(int *)(param_2 + 0xc) == 0) {
      iVar3 = param_1 + 0x14;
      iVar1 = FUN_600e72fc(iVar3,param_2);
      if (iVar1 != 0) {
        FUN_600e7480(iVar3);
        uVar4 = FUN_600e9414(iVar3);
        *(undefined8 *)(param_1 + 0x28) = uVar4;
        return 1;
      }
      uVar2 = 0x44;
      uVar5 = 0xb3;
    }
    else {
      uVar2 = 0x6d;
      uVar5 = 0xad;
    }
    FUN_600e0552(3,0,uVar2,DAT_6008b9ec,uVar5,iVar6,param_3);
  }
  else {
    FUN_600e0552(3,0,0x69,DAT_6008b9ec,0xa5,iVar6,param_3);
  }
  return 0;
}


