// 60058318  FUN_60058318  size=94 bytes
// --- callers ---
// --- callees ---
//   601019da FUN_601019da
//   60101a80 FUN_60101a80
//   600cdcc4 FUN_600cdcc4
//   600cc3cc FUN_600cc3cc
//   600cc450 FUN_600cc450


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_60058318(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = FUN_60101a80(*(undefined4 *)(param_1 + 0x14));
  uVar1 = FUN_600cc450(uVar1,PTR_s_commit_hash_6005837c,
                       PTR_s_c08b2dc60d39f9b83177c614c93146f6_60058378);
  uVar1 = FUN_600cc450(uVar1,PTR_s_version_6011ec49_0x13_60058384,PTR_s_337784_60058380);
  piVar2 = (int *)FUN_600cc450(uVar1,PTR_s_build_date_60058388,PTR_s_2023_01_12T22_41_20Z_6005838c);
  iVar4 = piVar2[2];
  iVar3 = FUN_600cc3cc(piVar2,PTR_s_local_modifications_60058390);
  if (iVar3 != 0) {
    FUN_600cdcc4(*piVar2 + piVar2[2],piVar2[1] - piVar2[2],PTR_s_false_60058394);
    FUN_601019da(piVar2,5,iVar4,0x7d);
  }
  uVar1 = FUN_600cc450(piVar2,_DAT_6005839c,PTR_s_gotham_dvt_60058398);
  iVar3 = FUN_600cc450(uVar1,_DAT_600583a4,_DAT_600583a0);
  return *(undefined1 *)(iVar3 + 0xd);
}


