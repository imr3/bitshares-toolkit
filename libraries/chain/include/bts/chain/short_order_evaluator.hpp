#pragma once
#include <bts/chain/evaluator.hpp>
#include <bts/chain/operations.hpp>
#include <bts/chain/database.hpp>

namespace bts { namespace chain {

   class short_order_create_evaluator : public evaluator<short_order_create_evaluator>
   {
      public:
         typedef short_order_create_operation operation_type;

         object_id_type do_evaluate( const short_order_create_operation& o );
         object_id_type do_apply( const short_order_create_operation& o );

         const short_order_create_operation* _op            = nullptr;
         const account_object*               _seller        = nullptr;
         const asset_object*                 _sell_asset    = nullptr;
         const asset_object*                 _receive_asset = nullptr;
         share_type                          _priority_fee  = 0;
   };

   class short_order_cancel_evaluator : public evaluator<short_order_cancel_evaluator>
   {
      public:
         typedef short_order_cancel_operation operation_type;

         asset do_evaluate( const short_order_cancel_operation& o );
         asset do_apply( const short_order_cancel_operation& o );

         const short_order_object* _order;
   };

   class call_order_update_evaluator : public evaluator<call_order_update_evaluator>
   {
      public:
         typedef call_order_update_operation operation_type;

         asset do_evaluate( const call_order_update_operation& o );
         asset do_apply( const call_order_update_operation& o );

         bool _closing_order = false;
         const asset_object* _debt_asset = nullptr;
         const account_object* _paying_account = nullptr;
         const call_order_object* _order = nullptr;
   };

} } // bts::chain
