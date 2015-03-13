#include <bts/chain/database.hpp>
#include <bts/chain/operations.hpp>
#include <bts/chain/key_object.hpp>
#include <bts/chain/account_object.hpp>
#include <bts/chain/short_order_object.hpp>
#include <bts/chain/limit_order_object.hpp>
#include <bts/chain/simple_index.hpp>

#include <fc/crypto/digest.hpp>

#include <boost/test/unit_test.hpp>

using namespace bts::chain;

BOOST_AUTO_TEST_SUITE( invariant_checks )

BOOST_AUTO_TEST_CASE( share_supply )
{
   try {
      database db;

      fc::ecc::private_key the_key = fc::ecc::private_key::generate();
      int count = 1;
      //Find a number of genesis recipients we can't distribute evenly to
      while( BTS_INITIAL_SUPPLY % ++count == 0 );
      genesis_allocation genesis;
      for( int i = 0; i < count; ++i )
         genesis.push_back(std::make_pair(public_key_type(the_key.get_public_key()), BTS_INITIAL_SUPPLY / count));
      db.init_genesis(genesis);

      BOOST_CHECK( account_id_type()(db).balances(db).get_balance(asset_id_type()).amount == 0 );
   } catch (fc::exception& e) {
      edump((e.to_detail_string()));
      throw;
   }
}

BOOST_AUTO_TEST_SUITE_END()