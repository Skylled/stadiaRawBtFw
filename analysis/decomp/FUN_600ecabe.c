// 600ecabe  FUN_600ecabe  size=140 bytes
// --- callers ---
// --- callees ---
//   6008f338 asn1_lib__6008f338
//   60091c10 obj__60091c10
//   600e092c FUN_600e092c


uint FUN_600ecabe(int *param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  if ((*(int *)(param_2 + 0x10) != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_2 + 0x10) + 8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600ecad6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  if (*param_2 == '\x05') {
    uVar1 = 0xffffffff;
switchD_600ecae6_caseD_fffffffd:
    puVar3 = (undefined4 *)asn1_lib__6008f338(uVar1);
    if ((*param_2 == '\x05') && (puVar3 != (undefined4 *)0x0)) {
      puVar3[3] = puVar3[3] | 0x40;
    }
LAB_600ecb22:
    *param_1 = (int)puVar3;
    uVar1 = (uint)(*param_1 != 0);
  }
  else {
    uVar1 = *(uint *)(param_2 + 4);
    switch(uVar1) {
    case 1:
      *param_1 = *(int *)(param_2 + 0x14);
      break;
    case 5:
      uVar1 = 1;
      *param_1 = 1;
      break;
    case 6:
      iVar2 = obj__60091c10(0);
      *param_1 = iVar2;
      uVar1 = 1;
      break;
    case 0xfffffffc:
      puVar3 = (undefined4 *)FUN_600e092c(8);
      if (puVar3 == (undefined4 *)0x0) {
        return 0;
      }
      *puVar3 = 0xffffffff;
      puVar3[1] = 0;
      goto LAB_600ecb22;
    default:
      goto switchD_600ecae6_caseD_fffffffd;
    }
  }
  return uVar1;
}


