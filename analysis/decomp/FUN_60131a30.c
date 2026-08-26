// 60131a30  FUN_60131a30  size=110 bytes
// --- callers ---
// --- callees ---
//   600b72f0 FUN_600b72f0


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_60131a30(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 in_cr7;
  undefined4 in_cr9;
  undefined8 in_d7;
  undefined8 extraout_d7;
  undefined8 uVar8;
  undefined1 in_q8 [16];
  
  uVar8 = in_q8._0_8_;
  if (*(code **)(DAT_60131d28 + 0x80) != (code *)0x0) {
    iVar3 = (**(code **)(DAT_60131d28 + 0x80))();
    uVar8 = in_q8._0_8_;
    in_d7 = extraout_d7;
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  if (*(char *)(DAT_60131d14 + 0x14) == '\0') {
    _UsageFault = 0;
    uVar4 = (uint)Reserved1;
    iVar3 = *(int *)(uVar4 + 4);
    uVar5 = *(undefined4 *)(uVar4 + 8);
    iVar6 = *(int *)(uVar4 + 0x10);
    iVar7 = iVar3 * 0x20;
    *(short *)(*(int *)(uVar4 + 0xc) + 0x30) = (short)iVar6;
    coprocessor_movefromRt(8,7,7,in_cr7,in_cr9);
    _DAT_1ad00109 = CONCAT11(DAT_1ad00109_1,(char)(iVar3 + -0xf8));
    uVar1 = *(ushort *)(iVar6 * 3);
    *(ushort *)(iVar6 + 2) = uVar1;
    uVar2 = _DAT_1ad00109;
    uVar4 = (uint)_DAT_1ad00109;
    *(char *)((uint)uVar1 + iVar6) = (char)uVar5;
    uVar1 = *(ushort *)(iVar7 + 0x14);
    *(short *)(iVar3 + -0xc) = ((short)(iVar3 + -0xf8) + 0xd0) * 2;
    _DAT_01a8000c = (int)(uint)uVar1 >> 0xb;
    *(undefined4 *)(iVar7 + 4) = 0x20;
    *(int *)(iVar3 * 0x10000) = iVar3 * 0x10000;
    *(ushort *)(iVar7 + 6) = uVar2;
    uVar5 = VectorGetElement(in_d7,1,4,0);
    VectorMultiplyAccumulate(uVar8,uVar5,4,1);
    return uVar4 << 0xb;
  }
  FUN_600b72f0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


