// 600ea868  bcm__600ea868  size=134 bytes
// src: bcm.c
// --- callers ---
//   60091580 ec_asn1__60091580
//   60085528 FUN_60085528
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   600edb24 FUN_600edb24
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600edafa FUN_600edafa
//   600e0552 FUN_600e0552
//   600e092c FUN_600e092c
//   600edaf6 FUN_600edaf6
//   600edafc FUN_600edafc
//   600919d4 ex_data__600919d4


/* WARNING: Removing unreachable block (ram,0x6008cda6) */
/* src: bcm.c */

int bcm__600ea868(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  iVar1 = FUN_600e092c(0x24);
  iVar4 = iVar1;
  if (iVar1 == 0) {
    FUN_600e0552(0xf,0,0x41,DAT_6008cdf8,0x6f,param_2,param_3);
  }
  else {
    thunk_EXT_FUN_0000af90(iVar1,0,0x24);
    if (*(int *)(iVar1 + 0x1c) != 0) {
      FUN_600edafa();
    }
    *(undefined1 *)(iVar1 + 0x14) = 4;
    *(undefined4 *)(iVar1 + 0x18) = 1;
    FUN_600edb24(iVar1 + 0x20);
    if (((*(int *)(iVar1 + 0x1c) != 0) &&
        (pcVar3 = *(code **)(*(int *)(iVar1 + 0x1c) + 0xc), pcVar3 != (code *)0x0)) &&
       (iVar2 = (*pcVar3)(iVar1), iVar2 == 0)) {
      ex_data__600919d4(DAT_6008cdfc,iVar1,iVar1 + 0x20);
      if (*(int *)(iVar1 + 0x1c) != 0) {
        FUN_600edafc();
      }
      iVar4 = 0;
      thunk_EXT_FUN_0000ac5e(iVar1);
    }
  }
  return iVar4;
}


