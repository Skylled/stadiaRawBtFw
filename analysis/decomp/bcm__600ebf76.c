// 600ebf76  bcm__600ebf76  size=156 bytes
// src: bcm.c
// --- callers ---
//   600868fc FUN_600868fc
//   60086824 FUN_60086824
// --- callees ---
//   600e0c4a FUN_600e0c4a
//   6013cee8 thunk_EXT_FUN_0000af90
//   600edaf2 FUN_600edaf2
//   600edb24 FUN_600edb24
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600edafa FUN_600edafa
//   600e0552 FUN_600e0552
//   600e092c FUN_600e092c
//   600edafc FUN_600edafc
//   6008ed58 FUN_6008ed58
//   600919d4 ex_data__600919d4
//   600e0c7e thunk_FUN_600ee0c8


/* WARNING: Removing unreachable block (ram,0x6008eda2) */
/* src: bcm.c */

int * bcm__600ebf76(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_600e092c(0x98);
  if (piVar1 == (int *)0x0) {
    FUN_600e0552(4,0,0x41,DAT_6008ee0c,0x5a,param_2,param_3);
  }
  else {
    thunk_EXT_FUN_0000af90(piVar1,0,0x98);
    if (*piVar1 == 0) {
      iVar2 = FUN_6008ed58();
      *piVar1 = iVar2;
    }
    FUN_600edafa(*piVar1);
    piVar1[10] = 1;
    piVar1[0xb] = *(int *)(*piVar1 + 0x28);
    FUN_600e0c4a(piVar1 + 0xc);
    FUN_600edb24(piVar1 + 9);
    if ((*(code **)(*piVar1 + 0xc) != (code *)0x0) &&
       (iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1), iVar2 == 0)) {
      ex_data__600919d4(DAT_6008ee10,piVar1,piVar1 + 9);
      thunk_FUN_600ee0c8(piVar1 + 0xc);
      FUN_600edafc(*piVar1);
      thunk_EXT_FUN_0000ac5e(piVar1);
      piVar1 = (int *)0x0;
    }
  }
  return piVar1;
}


