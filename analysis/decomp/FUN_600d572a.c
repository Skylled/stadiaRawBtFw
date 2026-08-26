// 600d572a  FUN_600d572a  size=68 bytes
// --- callers ---
// --- callees ---
//   600d56ae usb_host_worker__600d56ae
//   600d62f8 FUN_600d62f8


void FUN_600d572a(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  if ((param_4 == 0) && (*(int *)(param_1 + 0xf8) != *(int *)(param_1 + 0xfc))) {
    puVar1 = (undefined2 *)(*(int *)(param_1 + 0xfc) + -2);
    uVar2 = *puVar1;
    *(undefined2 **)(param_1 + 0xfc) = puVar1;
    FUN_600d62f8(*(undefined4 *)(param_1 + 0xec),uVar2,param_2,param_3,param_1);
    if (*(int *)(param_1 + 0xf8) == *(int *)(param_1 + 0xfc)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 7;
    }
  }
  else {
    uVar3 = 8;
  }
  usb_host_worker__600d56ae(param_1,uVar3);
  return;
}


