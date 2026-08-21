// 600ed09a  FUN_600ed09a  size=68 bytes
// --- callers ---
//   60091ddc FUN_60091ddc
//   60090fd0 FUN_60090fd0
// --- callees ---
//   600ecfae FUN_600ecfae
//   600ecf8c FUN_600ecf8c


undefined4 FUN_600ed09a(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((*(char *)((int)param_1 + 0xe) == '\0') && (iVar2 = FUN_600ecfae(), iVar2 != 0)) {
    puVar3 = (undefined4 *)*param_1;
    if (*(char *)(puVar3 + 3) == '\0') {
      if (param_2 != (undefined4 *)0x0) goto LAB_600ed0c0;
    }
    else {
      if ((param_2 == (undefined4 *)0x0) || (param_3 == (undefined4 *)0x0)) goto LAB_600ed0a6;
LAB_600ed0c0:
      *param_2 = *puVar3;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = puVar3[1];
    }
    *puVar3 = 0;
    FUN_600ecf8c(param_1);
    uVar1 = 1;
  }
  else {
LAB_600ed0a6:
    uVar1 = 0;
  }
  return uVar1;
}


