// 600f3aae  FUN_600f3aae  size=44 bytes
// --- callers ---
//   60134420 FUN_60134420
// --- callees ---
//   600ac524 FUN_600ac524


undefined1 FUN_600f3aae(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *unaff_r7;
  
  *(undefined2 *)(unaff_r7[2] + 0x2a) = *(undefined2 *)(*unaff_r7 + 0x16);
  iVar4 = unaff_r7[2];
  puVar2 = (undefined4 *)*unaff_r7;
  uVar1 = puVar2[1];
  uVar3 = puVar2[2];
  uVar5 = puVar2[3];
  *(undefined4 *)(iVar4 + 0x10) = *puVar2;
  *(undefined4 *)(iVar4 + 0x14) = uVar1;
  *(undefined4 *)(iVar4 + 0x18) = uVar3;
  *(undefined4 *)(iVar4 + 0x1c) = uVar5;
  *(undefined4 *)(iVar4 + 0x20) = puVar2[4];
  FUN_600ac524(unaff_r7[2]);
  return *(undefined1 *)((int)unaff_r7 + 0x17);
}


