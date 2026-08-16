// 60042c9c  FUN_60042c9c  size=134 bytes
// --- callers ---
// --- callees ---
//   60047958 FUN_60047958
//   6004c084 thunk_FUN_601016a2
//   60047aa8 tasks__60047aa8


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_60042c9c(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  puVar1 = *(uint **)(_DAT_60042ca8 + 0x78);
  if (puVar1 == (uint *)0x0) {
    thunk_FUN_601016a2(_DAT_600471b8,0x203,_DAT_600471b4);
  }
  if ((param_1 & 0xff000000) != 0) {
    thunk_FUN_601016a2(_DAT_600471b8,0x204,_DAT_600471b4);
  }
  FUN_60047958();
  uVar6 = 0;
  *puVar1 = *puVar1 | param_1;
  puVar7 = (uint *)puVar1[4];
LAB_60047172:
  do {
    puVar2 = puVar7;
    uVar3 = *puVar1;
    if (puVar2 == puVar1 + 3) {
      *puVar1 = uVar3 & ~uVar6;
      tasks__60047aa8();
      return *puVar1;
    }
    uVar4 = *puVar2;
    puVar7 = (uint *)puVar2[1];
    uVar5 = uVar4 & 0xffffff;
    if ((uVar4 & 0x4000000) != 0) goto LAB_600471a0;
  } while ((uVar5 & uVar3) == 0);
  goto LAB_600471a4;
LAB_600471a0:
  if (uVar5 == (uVar5 & uVar3)) {
LAB_600471a4:
    if ((int)(uVar4 << 7) < 0) {
      uVar6 = uVar6 | uVar5;
    }
    func_0x60047e08(puVar2,uVar3 | 0x2000000);
  }
  goto LAB_60047172;
}


