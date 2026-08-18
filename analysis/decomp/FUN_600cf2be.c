// 600cf2be  FUN_600cf2be  size=208 bytes
// --- callers ---
//   6006eb00 FUN_6006eb00
//   600ce708 FUN_600ce708
// --- callees ---
//   600cf1e6 FUN_600cf1e6
//   60053864 FUN_60053864
//   600538b4 FUN_600538b4


undefined4 FUN_600cf2be(undefined4 param_1,int param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (*(char *)(param_2 + 0x2d) == '\x03') {
    uVar2 = 0x515;
  }
  else {
    uVar5 = param_3[1];
    if (*(int *)(param_2 + 0x18) == 0) {
      iVar4 = *param_3;
      *(uint *)(param_2 + 0x14) = uVar5;
      *(int *)(param_2 + 0xc) = iVar4;
      *(uint *)(param_2 + 0x10) = uVar5;
      *(undefined1 *)(param_2 + 0x2d) = 3;
      FUN_60053864(param_1,0x8300000,param_3,3,param_4);
      uVar1 = 0;
    }
    else {
      FUN_600538b4(param_1,0x200000);
      uVar1 = FUN_600cf1e6(param_1,param_2);
      if (uVar1 != 0) {
        if (uVar5 <= uVar1) {
          uVar1 = uVar5;
        }
        uVar5 = uVar5 - uVar1;
        uVar3 = 0;
        while (uVar3 != uVar1) {
          *(undefined1 *)(*param_3 + uVar3) =
               *(undefined1 *)(*(int *)(param_2 + 0x18) + (uint)*(ushort *)(param_2 + 0x22));
          if (*(ushort *)(param_2 + 0x22) + 1 == *(int *)(param_2 + 0x1c)) {
            *(undefined2 *)(param_2 + 0x22) = 0;
            uVar3 = uVar3 + 1;
          }
          else {
            *(short *)(param_2 + 0x22) = *(short *)(param_2 + 0x22) + 1;
            uVar3 = uVar3 + 1;
          }
        }
      }
      if (uVar5 != 0) {
        iVar4 = *param_3;
        *(uint *)(param_2 + 0x14) = uVar5;
        *(uint *)(param_2 + 0xc) = iVar4 + uVar1;
        *(uint *)(param_2 + 0x10) = uVar5;
        *(undefined1 *)(param_2 + 0x2d) = 3;
      }
      FUN_60053864(param_1,0x200000);
      if ((uVar5 == 0) && (*(code **)(param_2 + 0x24) != (code *)0x0)) {
        (**(code **)(param_2 + 0x24))(param_1,param_2,0x517,*(undefined4 *)(param_2 + 0x28));
      }
    }
    if (param_4 == (uint *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      *param_4 = uVar1;
    }
  }
  return uVar2;
}


