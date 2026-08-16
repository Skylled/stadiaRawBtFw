// 600813cc  FUN_600813cc  size=92 bytes
// --- callers ---
//   60081ab4 gatt_server__60081ab4
// --- callees ---


undefined4 FUN_600813cc(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  uVar1 = DAT_60081428;
  if (*param_1 == '\0') {
    *param_1 = '\x01';
    iVar2 = DAT_6008142c;
    *(undefined4 *)(DAT_6008142c + 0x178) = uVar1;
    puVar3 = PTR_LAB_600df4fc_1_60081430;
    *(char **)(iVar2 + 0x17c) = param_1;
    *(undefined **)(iVar2 + 0x19c) = puVar3;
    puVar3 = PTR_LAB_600df500_1_60081434;
    *(char **)(iVar2 + 0x1a0) = param_1;
    *(char **)(iVar2 + 0x140) = param_1;
    *(char **)(iVar2 + 0x138) = param_1;
    *(char **)(iVar2 + 0x118) = param_1;
    *(undefined **)(iVar2 + 0x48) = puVar3;
    *(char **)(iVar2 + 0x4c) = param_1;
    *(undefined **)(iVar2 + 0x68) = PTR_LAB_600df4f4_1_60081438;
    *(char **)(iVar2 + 0x6c) = param_1;
    *(undefined **)(iVar2 + 0xac) = PTR_LAB_600df4f0_1_6008143c;
    *(char **)(iVar2 + 0xb0) = param_1;
    *(undefined **)(iVar2 + 0x13c) = PTR_LAB_600df53e_1_60081440;
    *(undefined **)(iVar2 + 0x134) = PTR_LAB_600df4ec_1_60081444;
    *(undefined **)(iVar2 + 0xf8) = PTR_LAB_600df54c_1_60081448;
    *(char **)(iVar2 + 0xfc) = param_1;
    *(undefined **)(iVar2 + 0x114) = PTR_thunk_FUN_600df4b0_1_6008144c;
  }
  return 0;
}


