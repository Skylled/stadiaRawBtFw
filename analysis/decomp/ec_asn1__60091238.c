// 60091238  ec_asn1__60091238  size=108 bytes
// src: ec_asn1.c
// --- callers ---
//   60085528 FUN_60085528
//   60091330 ec_asn1__60091330
// --- callees ---
//   600ed398 FUN_600ed398
//   600e0552 FUN_600e0552
//   6013d168 thunk_EXT_FUN_0000b554
//   600ed556 FUN_600ed556
//   6008cbe0 FUN_6008cbe0
//   600ed39c FUN_600ed39c
//   6008d7ac bcm__6008d7ac


/* src: ec_asn1.c */

undefined4
ec_asn1__60091238(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = param_3;
  uStack_14 = param_4;
  iVar1 = FUN_600ed556(param_1,&uStack_18,6,param_4,param_1,param_2);
  if (iVar1 == 0) {
    uVar4 = 0x80;
    uVar7 = 0x156;
  }
  else {
    iVar1 = FUN_6008cbe0();
    iVar6 = 0;
    puVar5 = (undefined4 *)(iVar1 + 4);
    do {
      uVar2 = FUN_600ed39c(&uStack_18);
      if ((uVar2 == *(byte *)(puVar5 + 1)) &&
         ((uVar4 = FUN_600ed398(&uStack_18), *(char *)(puVar5 + 1) == '\0' ||
          (iVar3 = thunk_EXT_FUN_0000b554(uVar4,*puVar5), iVar3 == 0)))) {
        uVar4 = bcm__6008d7ac(*(undefined4 *)(iVar1 + iVar6 * 0x1c));
        return uVar4;
      }
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 7;
    } while (iVar6 != 4);
    uVar4 = 0x7b;
    uVar7 = 0x165;
  }
  FUN_600e0552(0xf,0,uVar4,DAT_600912a4,uVar7);
  return 0;
}


