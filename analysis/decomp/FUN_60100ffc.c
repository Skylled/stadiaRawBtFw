// 60100ffc  FUN_60100ffc  size=204 bytes
// --- callers ---
//   6010112c FUN_6010112c
//   60101198 FUN_60101198
// --- callees ---
//   60100e08 FUN_60100e08
//   600cb460 key_value_store__600cb460
//   60100b6a FUN_60100b6a
//   600cb39c key_value_store__600cb39c
//   600db002 FUN_600db002
//   60100d98 FUN_60100d98
//   60100c48 FUN_60100c48


char FUN_60100ffc(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar7 = param_3;
  iVar2 = key_value_store__600cb460();
  if (iVar2 == 0) {
    uVar3 = FUN_600db002(param_1 + param_2 * 6 + 0x56,0x10);
    if (uVar3 < 0x10) {
      uVar4 = FUN_60100b6a(param_1,uVar3 & 0xffff,param_4);
      uVar6 = *(uint *)(*(int *)(*param_1 + 4) + 4);
      if ((uint)param_1[(uint)param_1[param_2 * 6 + 0x5a] / uVar6 + 0x1a] < uVar4) {
        cVar1 = FUN_60100d98(param_1);
        if (cVar1 != '\0') {
          return cVar1;
        }
        uVar5 = FUN_60100b6a(param_1,uVar3 & 0xffff,param_4);
        iVar2 = FUN_60100e08(param_1,uVar5);
      }
      else {
        iVar2 = (((uint)param_1[param_2 * 6 + 0x5a] / uVar6) * uVar6 + uVar6) -
                param_1[(uint)param_1[param_2 * 6 + 0x5a] / uVar6 + 0x1a];
      }
      if (iVar2 == -1) {
        cVar1 = '\b';
      }
      else {
        cVar1 = FUN_60100c48(param_1,iVar2,param_1 + param_2 * 6 + 0x56,param_3,param_4,param_5,
                             uVar7);
        if (cVar1 == '\0') {
          param_1[param_2 * 6 + 0x5a] = iVar2;
          *(short *)(param_1 + param_2 * 6 + 0x5b) = (short)param_4;
          *(undefined1 *)((int)param_1 + param_2 * 0x18 + 0x16e) = param_5;
          cVar1 = key_value_store__600cb39c(param_1);
        }
      }
    }
    else {
      cVar1 = '\r';
    }
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}


