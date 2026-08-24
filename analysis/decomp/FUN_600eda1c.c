// 600eda1c  FUN_600eda1c  size=72 bytes
// --- callers ---
//   60091330 ec_asn1__60091330
// --- callees ---
//   600ed398 FUN_600ed398
//   600ed3a0 FUN_600ed3a0
//   600ed39c FUN_600ed39c
//   600ed380 FUN_600ed380


void FUN_600eda1c(undefined4 *param_1,char *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  while ((iVar1 = FUN_600ed39c(&local_18), iVar1 != 0 &&
         (pcVar2 = (char *)FUN_600ed398(&local_18), *pcVar2 == '\0'))) {
    FUN_600ed380(&local_18,1);
  }
  while ((param_3 != 0 && (*param_2 == '\0'))) {
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  }
  FUN_600ed3a0(&local_18,param_2,param_3);
  return;
}


