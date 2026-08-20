// 600eaba4  FUN_600eaba4  size=556 bytes
// --- callers ---
//   600eafdc FUN_600eafdc
//   600eb7ce FUN_600eb7ce
//   600eb156 FUN_600eb156
// --- callees ---
//   600e9746 FUN_600e9746
//   600ea89c FUN_600ea89c
//   600eab3a FUN_600eab3a
//   600ea8ba FUN_600ea8ba
//   600e972c FUN_600e972c
//   600eab8c FUN_600eab8c
//   600ea8d8 FUN_600ea8d8


void FUN_600eaba4(undefined4 param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_4ac [68];
  undefined1 auStack_468 [68];
  undefined1 auStack_424 [68];
  undefined1 auStack_3e0 [68];
  undefined1 auStack_39c [68];
  undefined1 auStack_358 [68];
  undefined1 auStack_314 [68];
  undefined1 auStack_2d0 [68];
  undefined1 auStack_28c [68];
  undefined1 auStack_248 [68];
  undefined1 auStack_204 [68];
  undefined1 auStack_1c0 [68];
  undefined1 auStack_17c [68];
  undefined1 auStack_138 [68];
  undefined1 auStack_f4 [68];
  undefined1 auStack_b0 [68];
  undefined1 auStack_6c [72];
  
  if (param_3 != param_4) {
    iVar5 = param_3 + 0x88;
    iVar6 = param_4 + 0x88;
    uVar1 = FUN_600eab3a(param_1,iVar5);
    uVar2 = FUN_600eab3a(param_1,iVar6);
    FUN_600e9746(param_1,auStack_3e0,iVar5);
    FUN_600e9746(param_1,auStack_39c,iVar6);
    FUN_600e972c(param_1,auStack_358,param_3,auStack_39c);
    FUN_600ea89c(param_1,auStack_314,iVar5,iVar6);
    FUN_600e9746(param_1,auStack_314);
    FUN_600ea8ba(param_1,auStack_314,auStack_314,auStack_3e0);
    FUN_600ea8ba(param_1,auStack_314,auStack_314,auStack_39c);
    FUN_600e972c(param_1,auStack_2d0,iVar6,auStack_39c);
    FUN_600e972c(param_1,auStack_2d0);
    FUN_600e972c(param_1,auStack_28c,param_4,auStack_3e0);
    FUN_600ea8ba(param_1,auStack_248,auStack_28c,auStack_358);
    uVar3 = FUN_600eab3a(param_1,auStack_248);
    FUN_600e972c(param_1,auStack_424,auStack_248,auStack_314);
    FUN_600e972c(param_1,auStack_204,iVar5,auStack_3e0);
    FUN_600e972c(param_1,auStack_1c0,param_4 + 0x44,auStack_204);
    FUN_600ea8ba(param_1,auStack_17c,auStack_1c0,auStack_2d0);
    FUN_600ea89c(param_1,auStack_17c,auStack_17c);
    uVar4 = FUN_600eab3a(param_1,auStack_17c);
    if ((uVar1 & uVar2 & ~(uVar3 | uVar4)) == 0) {
      FUN_600ea89c(param_1,auStack_138,auStack_248);
      FUN_600e9746(param_1,auStack_138);
      FUN_600e972c(param_1,auStack_f4,auStack_248,auStack_138);
      FUN_600e972c(param_1,auStack_b0,auStack_358,auStack_138);
      FUN_600e9746(param_1,auStack_4ac,auStack_17c);
      FUN_600ea8ba(param_1,auStack_4ac,auStack_4ac,auStack_f4);
      FUN_600ea8ba(param_1,auStack_4ac,auStack_4ac,auStack_b0);
      FUN_600ea8ba(param_1,auStack_4ac,auStack_4ac,auStack_b0);
      FUN_600ea8ba(param_1,auStack_468,auStack_b0,auStack_4ac);
      FUN_600e972c(param_1,auStack_468,auStack_468,auStack_17c);
      FUN_600e972c(param_1,auStack_6c,auStack_2d0,auStack_f4);
      FUN_600ea8ba(param_1,auStack_468,auStack_468,auStack_6c);
      FUN_600ea8ba(param_1,auStack_468,auStack_468,auStack_6c);
      FUN_600eab8c(param_1,auStack_4ac,uVar1,auStack_4ac,param_4);
      FUN_600eab8c(param_1,param_2,uVar2,auStack_4ac,param_3);
      FUN_600eab8c(param_1,auStack_468,uVar1,auStack_468,param_4 + 0x44);
      FUN_600eab8c(param_1,param_2 + 0x44,uVar2,auStack_468,param_3 + 0x44);
      FUN_600eab8c(param_1,auStack_424,uVar1,auStack_424,iVar6);
      FUN_600eab8c(param_1,param_2 + 0x88,uVar2,auStack_424,iVar5);
      return;
    }
  }
  FUN_600ea8d8(param_1,param_2,param_3);
  return;
}


