// 60100c48  FUN_60100c48  size=232 bytes
// --- callers ---
//   60100ffc FUN_60100ffc
//   60101198 FUN_60101198
// --- callees ---
//   60100b6a FUN_60100b6a
//   60101848 FUN_60101848
//   60100c14 FUN_60100c14
//   60100b24 FUN_60100b24
//   600db002 FUN_600db002


uint FUN_60100c48(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,short param_5,
                 undefined1 param_6)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 local_30;
  uint local_2e;
  ushort local_2a;
  
  uVar1 = FUN_600db002(param_3,0x10);
  if (uVar1 < 0x10) {
    local_2e = 0;
    local_2a = 0;
    local_30 = 0x55aa;
    uVar2 = FUN_60100c14(param_1,param_3,uVar1,param_4,param_5);
    local_2e = (uint)CONCAT12(param_6,uVar2);
    local_2a = (ushort)((byte)uVar1 & 0xf);
    local_2a = local_2a | param_5 << 4;
    uVar6 = *(uint *)(*(int *)(*param_1 + 4) + 4);
    uVar3 = FUN_60101848(*param_1,param_2,&local_30);
    if ((uVar3 & 0xff) == 0) {
      iVar4 = FUN_60100b24(*(undefined1 *)((int)param_1 + 0x59),8);
      uVar3 = FUN_60101848(*param_1,iVar4 + param_2,param_3,uVar1);
      if (((uVar3 & 0xff) == 0) &&
         ((iVar5 = FUN_60100b24(*(undefined1 *)((int)param_1 + 0x59),uVar1), param_5 == 0 ||
          (uVar3 = FUN_60101848(*param_1,iVar5 + iVar4 + param_2,param_4,param_5),
          (uVar3 & 0xff) == 0)))) {
        iVar4 = FUN_60100b6a(param_1,uVar1,param_5);
        param_2 = param_2 / uVar6;
        param_1[param_2 + 0x1a] = param_1[param_2 + 0x1a] - iVar4;
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 0xd;
  }
  return uVar3;
}


