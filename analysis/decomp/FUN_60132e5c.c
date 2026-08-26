// 60132e5c  FUN_60132e5c  size=272 bytes
// --- callers ---
// --- callees ---


/* WARNING: Instruction at (ram,0x60133084) overlaps instruction at (ram,0x60133082)
    */
/* WARNING: Removing unreachable block (ram,0x60132ea2) */
/* WARNING: Removing unreachable block (ram,0x6013306a) */
/* WARNING: Removing unreachable block (ram,0x60133074) */
/* WARNING: Removing unreachable block (ram,0x60133084) */
/* WARNING: Removing unreachable block (ram,0x6013307e) */
/* WARNING: Removing unreachable block (ram,0x60133082) */
/* WARNING: Removing unreachable block (ram,0x60133094) */
/* WARNING: Removing unreachable block (ram,0x6013312e) */
/* WARNING: Removing unreachable block (ram,0x601330a0) */
/* WARNING: Removing unreachable block (ram,0x6013306e) */
/* WARNING: Removing unreachable block (ram,0x601330c0) */
/* WARNING: Removing unreachable block (ram,0x60133146) */
/* WARNING: Removing unreachable block (ram,0x60133072) */
/* WARNING: Removing unreachable block (ram,0x601330a2) */
/* WARNING: Removing unreachable block (ram,0x601330c4) */
/* WARNING: Removing unreachable block (ram,0x601330b6) */

undefined8 FUN_60132e5c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 unaff_r8;
  undefined4 in_r12;
  undefined4 in_cr15;
  
  uVar2 = 0;
  puVar3 = param_2;
  puVar5 = DAT_60132ecc;
  if (*(char *)((int)DAT_60132ecc + 9) != '\0') {
    coprocessor_moveto2(0xc,0xf,unaff_r8,in_r12,in_cr15);
    *(uint *)(*(byte *)(param_1 + 0xda) + 0x70) = (uint)*(byte *)(param_1 + 0xda);
    uVar1 = *param_2;
    puVar3 = (undefined4 *)param_2[1];
    iVar4 = param_2[2];
    puVar5 = (undefined4 *)param_2[3];
    param_2 = (undefined4 *)param_2[5];
    *(undefined4 **)(iVar4 + 0x30) = puVar3;
    *(short *)(iVar4 + 0x10) = (short)uVar1;
    param_1 = 0xf7;
    uVar2 = (int)param_2 << 7;
  }
  do {
    *(undefined4 **)(param_1 + 0x20) = puVar3;
    *(short *)(param_1 + 0x10) = (short)uVar2;
    uVar2 = (uint)param_2 >> 3;
    param_2 = puVar5;
  } while (-1 < (int)puVar5);
  return CONCAT44(puVar3,uVar2);
}


