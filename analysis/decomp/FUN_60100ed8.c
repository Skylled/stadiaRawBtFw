// 60100ed8  FUN_60100ed8  size=184 bytes
// --- callers ---
//   60100f90 FUN_60100f90
//   60101294 FUN_60101294
// --- callees ---
//   60100b6a FUN_60100b6a
//   60100e08 FUN_60100e08
//   60100d30 FUN_60100d30
//   600cb270 FUN_600cb270
//   600db002 FUN_600db002
//   60100eaa FUN_60100eaa


uint FUN_60100ed8(int *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  bVar5 = 0;
  do {
    uVar4 = (uint)bVar5;
    if (*(byte *)(param_1 + 0x2ae) <= uVar4) {
      FUN_600cb270(param_1,param_2,param_3,(uint)*(byte *)(param_1 + 0x2ae),param_4);
      return 0;
    }
    while (param_3 = (uint)*(byte *)(param_1 + 0x2ae), uVar4 < param_3) {
      uVar6 = param_1[uVar4 * 6 + 0x5a];
      param_3 = uVar6 / *(uint *)(*(int *)(*param_1 + 4) + 4);
      if (param_2 != param_3) break;
      if (*(char *)((int)param_1 + uVar4 * 0x18 + 0x16e) == '\0') {
        uVar1 = FUN_600db002(param_1 + uVar4 * 6 + 0x56,0x10);
        iVar2 = FUN_60100b6a(param_1,uVar1,(short)param_1[uVar4 * 6 + 0x5b]);
        uVar3 = FUN_60100e08(param_1,iVar2);
        if (uVar3 == 0xffffffff) {
          return 8;
        }
        uVar6 = FUN_60100d30(param_1,uVar3,uVar6,iVar2);
        if ((uVar6 & 0xff) != 0) {
          return uVar6;
        }
        uVar6 = uVar3 / *(uint *)(*(int *)(*param_1 + 4) + 4);
        param_3 = param_1[uVar6 + 0x1a];
        param_1[uVar6 + 0x1a] = param_3 - iVar2;
        param_1[uVar4 * 6 + 0x5a] = uVar3;
        break;
      }
      FUN_60100eaa(param_1,uVar4);
    }
    bVar5 = bVar5 + 1;
  } while( true );
}


