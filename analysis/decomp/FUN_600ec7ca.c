// 600ec7ca  FUN_600ec7ca  size=234 bytes
// --- callers ---
//   600ec8b4 FUN_600ec8b4
// --- callees ---
//   600ec38c FUN_600ec38c
//   600ec438 FUN_600ec438
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1 * FUN_600ec7ca(int *param_1,int param_2,int *param_3,char *param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  int local_24 [2];
  undefined1 local_19 [5];
  
  local_24[0] = param_2;
  if ((*(int *)(param_4 + 0x10) != 0) &&
     (pcVar4 = *(code **)(*(int *)(param_4 + 0x10) + 0x18), pcVar4 != (code *)0x0)) {
    puVar1 = (undefined1 *)(*pcVar4)();
    return puVar1;
  }
  if ((*param_4 == '\0') && (*(int *)(param_4 + 4) == 1)) {
LAB_600ec818:
    if (*(int *)(param_4 + 4) != -4) {
      puVar1 = (undefined1 *)*param_3;
      goto LAB_600ec804;
    }
    piVar5 = (int *)*param_1;
    param_1 = piVar5 + 1;
    puVar1 = (undefined1 *)*piVar5;
  }
  else {
    if (*param_1 == 0) {
      return (undefined1 *)0xffffffff;
    }
    if (*param_4 != '\x05') goto LAB_600ec818;
    puVar1 = *(undefined1 **)(*param_1 + 4);
  }
  *param_3 = (int)puVar1;
LAB_600ec804:
  switch(puVar1) {
  case (undefined1 *)0x1:
    iVar3 = *param_1;
    if (iVar3 == -1) {
      return (undefined1 *)0xffffffff;
    }
    if (*(int *)(param_4 + 4) != -4) {
      if (iVar3 == 0) {
        if (*(int *)(param_4 + 0x14) == 0) {
          return (undefined1 *)0xffffffff;
        }
      }
      else if (0 < *(int *)(param_4 + 0x14)) {
        return (undefined1 *)0xffffffff;
      }
    }
    puVar2 = local_19;
    local_19[0] = (undefined1)iVar3;
    break;
  case (undefined1 *)0x2:
  case (undefined1 *)0xa:
    piVar5 = (int *)0x0;
    if (param_2 != 0) {
      piVar5 = local_24;
    }
    puVar1 = (undefined1 *)FUN_600ec438(*param_1,piVar5);
    return puVar1;
  case (undefined1 *)0x3:
    piVar5 = (int *)0x0;
    if (param_2 != 0) {
      piVar5 = local_24;
    }
    puVar1 = (undefined1 *)FUN_600ec38c(*param_1,piVar5);
    return puVar1;
  default:
    param_1 = (int *)*param_1;
    if ((*(int *)(param_4 + 0x14) == 0x800) && (param_1[3] << 0x1b < 0)) {
      if (param_2 != 0) {
        param_1[2] = param_2;
        *param_1 = 0;
      }
      return (undefined1 *)0xfffffffe;
    }
    puVar2 = (undefined1 *)param_1[2];
    puVar1 = (undefined1 *)*param_1;
    break;
  case (undefined1 *)0x5:
    puVar2 = (undefined1 *)0x0;
    puVar1 = puVar2;
    break;
  case (undefined1 *)0x6:
    puVar1 = *(undefined1 **)(*param_1 + 0xc);
    puVar2 = *(undefined1 **)(*param_1 + 0x10);
    if (puVar2 == (undefined1 *)0x0) {
      return (undefined1 *)0xffffffff;
    }
    if (puVar1 == (undefined1 *)0x0) {
      return (undefined1 *)0xffffffff;
    }
  }
  if (param_2 == 0) {
    return puVar1;
  }
  if (puVar1 != (undefined1 *)0x0) {
    thunk_EXT_FUN_0000b572(param_2,puVar2,puVar1);
    return puVar1;
  }
  return (undefined1 *)0x0;
}


